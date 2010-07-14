<?php
// $Id$

function databasics_views_data() {
  // Basic table information.

  // ----------------------------------------------------------------
  // Core databasics table

  // Define the base group of this table. Fields that don't
  // have a group defined will go into this field by default.
  $data['databasics']['table']['group']  = t('Databasics statistics');

  $data['databasics']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  // The number of times a node has been viewed
  $data['databasics']['view_count'] = array(
    'title' => t('ViewMaster count'),
    'help' => t('The total number of times the node has been viewed.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // The number of times a node has been viewed
  $data['databasics']['last_viewed'] = array(
    'title' => t('Timestamp'),
    'help' => t('Timestamp of when the page was visited.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // user
  $data['databasics']['uid'] = array(
    'title' => t('User'),
    'help' => t('The user who visited the site.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
     ),
  );

  // node
  $data['databasics']['nid'] = array(
    'title' => t('Node'),
    'help' => t('The node that was viewed.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
     ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function databasics_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views') . '/modules/databasics',
    ),
    'handlers' => array(
      'databasics_field_numerify' => array(
        'parent' => 'views_handler_field_numeric',
      ),
    ),
  );
}
