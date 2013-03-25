<?php

/**
 * Implements hook_views_data().
 */
function databasics_views_data() {
  $data = array();

  // Define the group this table and its fields should appear under
  // in the Views administrative interface.
  $data['databasics']['table']['group'] = t('Databasics');

  // Advertise this table as a possible base table. This makes it possible
  // to create a standalone view of "Databasics" entries.
  $data['databasics']['table']['base'] = array(
    'title' => t('Databasics'),
    'help' => t('Stores node visits for users.'),
  );

  // This tells Views about the base tables that Databasics'
  // foreign keys point to. If you make a View of THESE base tables,
  // Databasics fields will be available too.
  $data['databasics']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid', // The column in the node table
      'field' => 'nid',      // The column in our table
    ),
    'user' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  // Node NID field.
  $data['databasics']['nid'] = array(
    'title' => t('Nid'),
    'help' => t('The node ID.'), // The help that appears on the UI,
    // Information for displaying the nid
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
    // Information for accepting a nid as an argument.
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
      'numeric' => TRUE,
      'validate type' => 'nid',
    ),
    // Information for accepting a nid as a filter.
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    // Information for sorting on a nid.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    // Information for creating a relationship.
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Node'),
    ),
  );

  // User UID field.
  $data['databasics']['uid'] = array(
    'title' => t('User ID'),
    'help' => t("The User that viewed the node."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
    'sort' => array(
      'handler' => 'databasics_handler_sort_custom',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('Visitor'),
    ),
  );

  // View count field.
  $data['databasics']['view_count'] = array(
    'title' => t('Visits'),
    'help' => t('The number of times the node has been viewed.'),
    'field' => array(
      'handler' => 'databasics_handler_field_percent',
      'click sortable' => TRUE,
    ),
    // ORDER BY clause in our SQL builder.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    // Filter handler.
    'filter' => array(
      'handler' => 'databasics_handler_filter_numeric',
    ),
  );

  // Displaying the View count field as a graph.
  $data['databasics']['view_count_percent'] = array(
    'title' => t('Visits graph'),
    'help' => t('The number of times the node has been viewed displayed as a bar graph.'),
    'real field' => 'view_count',
    'field' => array(
      'handler' => 'databasics_handler_field_percent_graph',
    ),
  );

  // Last visited field.
  $data['databasics']['last_viewed'] = array(
    'title' => t('Last visit'),
    'help' => t('Timestamp of when the page was visited.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  // Adding an area.
  $data['databasics']['databasics_area'] = array(
    'title' => t('Databasics Area'),
    'help' => t('Some help text.'),
    'area' => array(
      'handler' => 'databasics_handler_area_databasics',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function databasics_views_plugins() {
  return array(
    'access' => array(
      'databasics' => array(
        'title' => t('Databasics'),
        'help' => t('Determines access to Databasics tab'),
        'handler' => 'databasics_plugin_access',
        'uses options' => TRUE,
      ),
    ),
  );
}



