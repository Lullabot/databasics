<?php
/**
 * @file
 * Drush command file.
 */

/**
 * Implements hook_drush_command().
 */
function databasics_drush_command() {
  $items['databasics-content'] = array(
    'description' => 'Create dummy content for databasics table.',
    'arguments' => array(
      'number' => 'Maximum number of records to add to a node.',
    ),
    'options' => array(
      'purge' => 'Delete all existing records before generating new ones.',
    ),
    'examples' => array(
      'drush dbgenc 25' => 'Generate 25 records for the databasics table.',
      'drush dbgenc 10 --purge=1' => 'Delete all existing records and generate 10 new ones.',
    ),
    'aliases' => array('dbgenc'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'core' => array('7+'),
    'drupal dependencies' => array('databasics'),
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 */
function databasics_drush_help($section) {
  switch($section) {
    case 'drush:databasics-content':
      return dt('This command can be used to generate records for the databasics module. It is useful when you need to have a bunch of random content for testing things out.');
      break;
  }
};

/**
 * Validation for databasics-content command.
 */
function drush_databasics_content_validate($number = FALSE) {
  if (!$number) {
    $options = array(
      10 => dt('10 records'),
      20 => dt('20 records'),
      30 => dt('30 records'),
    );
    $number = drush_choice($options, dt('How many records would you like to generate?'));
  }

  if (!is_numeric($number) || $number < 0) {
    return drush_set_error('DATABASICS_ERROR', dt('"@number" is not a valid argument. Please specify a positive integer.', array('@number' => $number)));
  }
}

function drush_databasics_content($number = FALSE) {
  if (drush_get_option('purge', FALSE)) {
    if (!drush_confirm('Are you sure you want to delete the records from the database?')) {
      drush_user_abort();
      return;
    }
    $num = db_delete('databasics')->execute();
    drush_log(dt('Deleted @num records.', array('@num' => $num)), 'success');
  }

  // Get a list of all the user's currently defined.
  $users = db_select('users', 'u')
    ->fields('u', array('uid'))
    ->execute()
    ->fetchCol();

  // Get a list of all the nodes.
  $nids = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->execute()
    ->fetchCol();

  if (count($nids) <= 0) {
    drush_set_error('DATABASICS_ERROR', dt('There are no nodes to generate records for.'));
    return;
  }

  // Add a record to each node using a random user and a random view count
  // between 1 and 25.
  foreach ($nids as $nid) {
    $record = new stdClass();
    $record->nid = $nid;
    $num = $number;
    while ($num > 0) {
      $record->uid = array_rand($users);
      $record->view_count = rand(1, 25);
      // Between now and 1 week ago.
      $record->last_viewed = REQUEST_TIME - rand(0, 604800);
      databasics_set_record($record);
      $num--;
    }

  }

  drush_log(dt('Generated databasics content.'), 'ok');

}


