<?php
// $Id$

function databasics_views_data() {
  // Basic table information.

  // ----------------------------------------------------------------
  // Databasics table

  // Define the group this table and its fields should appear in in the Views
  // Administrative interface.
  $data['databasics']['table']['group']  = t('Databasics');

  // Advertise this table as a possible base table. This makes it possible
  // to create a standalone view of "Databasics" entries.
  $data['databasics']['table']['base'] = array(
    // 'field' => 'whoops', // If our table had a primary key it would go here.
    'title' => t('Databasics'),
    'help' => t('Stores node visits for users.'),
  );

  // This tells Views about the base tables that Databasics' foreign keys point
  // to. If you make a View of THESE base tables, Databasics fields will be
  // available, too.
  $data['databasics']['table']['join'] = array(
   'node' => array(
      'left_field' => 'nid', // The column in the node table
      'field' => 'nid',      // The column in our table
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  // The number of times a node has been viewed
  $data['databasics']['view_count'] = array(
    'title' => t('Visits'),
    'help' => t('The number of times the node has been viewed.'),
    
    // This tells Views that the column can be used for display purposes,
    // specifies what Field Handler should be responsible for building its
    // SQL, rendering its value to the user, and so on.
    'field' => array(
      'handler' => 'databasics_field_numerify',
      'click sortable' => TRUE,
     ),

    // This tells Views that the column can be used for sorting, and
    // specifies what Sort handler should be responsible for building its
    // ORDER BY clause, settings page, etc. We're using the built-in handler.
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),

    // This tells Views that the column can be used for filtering, and
    // specifies what Filter handler should be responsible for building its
    // WHERE clause, settings page, etc. We're using the built-in handler.
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  // The last time a node was viewed
  $data['databasics']['last_viewed'] = array(
    'title' => t('Last visit'),
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

  // The ID of the node that was viewed.
  $data['databasics']['nid'] = array(
    'title' => t('Node ID'),
    'help' => t('The Node that was viewed.'),
    'field' => array(
      'handler' => 'views_handler_field_node',
    ),
    
    // This tells Views that the 'nid' column should be usable as an argument,
    // and specifies which PHP class should handle processing it.
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
    ),

    // This tells Views that the 'nid' can be used as a pointer to the full Node
    // table, notes what column should be used to construct the join, and what
    // PHP Class should handle building the SQL Join.
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Node'),
    ),
  );

  // The ID of the user that did the viewing.
  $data['databasics']['uid'] = array(
    'title' => t('User ID'),
    'help' => t("The User that viewed the node."),
    'field' => array(
      'handler' => 'views_handler_field_user',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
    ),
    'relationship' => array(
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User'),
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
    // This tells Views where to find the .inc files for this module's custom
    // handlers.
    'info' => array(
      'path' => drupal_get_path('module', 'databasics') ,
    ),
    
    // This lists out each custom handler our moduledefines.
    'handlers' => array(
      'databasics_field_numerify' => array(
        // If our handler inherits from an existing one, we list its PHP class.
        'parent' => 'views_handler_field_numeric',
        // If the class name matches the filename, we can leave 'file' out.
        'file' => 'databasics_field_numerify.inc',
      ),
    ),
  );
}
