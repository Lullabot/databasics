<?php

/**
 * Implement hook_views_default_views().
 */
function databasics_views_default_views() {
  /*
   * View 'databasics_visitors'
   */
  $view = new view;
  $view->name = 'databasics_visitors';
  $view->description = 'Displays a list of users who have visited a given node.';
  $view->tag = 'databasics';
  $view->base_table = 'users';
  $view->human_name = 'Databasics Visitors';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'last_viewed' => 'last_viewed',
    'view_count' => 'view_count',
  );
  $handler->display->display_options['style_options']['default'] = 'last_viewed';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'last_viewed' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'view_count' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['order'] = 'desc';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Databasics: Last visit */
  $handler->display->display_options['fields']['last_viewed']['id'] = 'last_viewed';
  $handler->display->display_options['fields']['last_viewed']['table'] = 'databasics';
  $handler->display->display_options['fields']['last_viewed']['field'] = 'last_viewed';
  $handler->display->display_options['fields']['last_viewed']['label'] = 'Time of visit';
  $handler->display->display_options['fields']['last_viewed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['last_viewed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['last_viewed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['last_viewed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['last_viewed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['last_viewed']['date_format'] = 'time ago';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['view_count']['id'] = 'view_count';
  $handler->display->display_options['fields']['view_count']['table'] = 'databasics';
  $handler->display->display_options['fields']['view_count']['field'] = 'view_count';
  $handler->display->display_options['fields']['view_count']['label'] = 'Number of visits';
  $handler->display->display_options['fields']['view_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_count']['empty_zero'] = 0;
  /* Argument: Databasics: Node ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'databasics';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['title'] = '%1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filter: Databasics: Visits */
  $handler->display->display_options['filters']['view_count']['id'] = 'view_count';
  $handler->display->display_options['filters']['view_count']['table'] = 'databasics';
  $handler->display->display_options['filters']['view_count']['field'] = 'view_count';
  $handler->display->display_options['filters']['view_count']['operator'] = '>';
  $handler->display->display_options['filters']['view_count']['value']['value'] = '0';
  $handler->display->display_options['filters']['view_count']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'node/%/databasics';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Databasics';
  $handler->display->display_options['menu']['weight'] = '10';
  $translatables['databasics_visitors'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('User'),
    t('Time of visit'),
    t('Number of visits'),
    t('All'),
    t('%1'),
    t('Page'),
  );
  $views[$view->name] = $view;

  /*
   * View 'databasics_visits'
   */
  $view = new view;
  $view->name = 'databasics_visits';
  $view->description = 'Displays nodes a given users has visited';
  $view->tag = 'databasics';
  $view->base_table = 'node';
  $view->human_name = 'Databasics Visits';
  $view->core = 0;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'last_viewed' => 'last_viewed',
    'view_count' => 'view_count',
  );
  $handler->display->display_options['style_options']['default'] = 'last_viewed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'last_viewed' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'view_count' => array(
      'sortable' => 1,
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['order'] = 'desc';
  /* Field: Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Node';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Databasics: Last visit */
  $handler->display->display_options['fields']['last_viewed']['id'] = 'last_viewed';
  $handler->display->display_options['fields']['last_viewed']['table'] = 'databasics';
  $handler->display->display_options['fields']['last_viewed']['field'] = 'last_viewed';
  $handler->display->display_options['fields']['last_viewed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['last_viewed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['last_viewed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['last_viewed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['last_viewed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['last_viewed']['date_format'] = 'time ago';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['view_count']['id'] = 'view_count';
  $handler->display->display_options['fields']['view_count']['table'] = 'databasics';
  $handler->display->display_options['fields']['view_count']['field'] = 'view_count';
  $handler->display->display_options['fields']['view_count']['label'] = 'Number of visits';
  $handler->display->display_options['fields']['view_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_count']['empty_zero'] = 0;
  /* Argument: Databasics: User ID */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'databasics';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['style_plugin'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['title'] = '%1';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'user/%/databasics';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Databasics';
  $handler->display->display_options['menu']['weight'] = '10';
  $translatables['databasics_visits'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort By'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Node'),
    t('Last visit'),
    t('Number of visits'),
    t('All'),
    t('%1'),
    t('Page'),
  );
  $views[$view->name] = $view;

  return $views;
}
