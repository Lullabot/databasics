<?php

/**
 * Implement hook_views_default_views().
 */
function databasics_views_default_views() {
  $view = new view;
  $view->name = 'databasics_node_visitors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'databasics';
  $view->human_name = 'Databasics Node Visitors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Databasics Node Visitors';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'last_viewed' => 'last_viewed',
    'view_count' => 'view_count',
    'view_count_percent' => 'view_count_percent',
  );
  $handler->display->display_options['style_options']['default'] = 'view_count';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_viewed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_count_percent' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Databasics: Nid */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'databasics';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = 0;
  /* Relationship: Databasics: User ID */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'databasics';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Databasics: Last visit */
  $handler->display->display_options['fields']['last_viewed']['id'] = 'last_viewed';
  $handler->display->display_options['fields']['last_viewed']['table'] = 'databasics';
  $handler->display->display_options['fields']['last_viewed']['field'] = 'last_viewed';
  $handler->display->display_options['fields']['last_viewed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['last_viewed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['last_viewed']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['last_viewed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['last_viewed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['last_viewed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['last_viewed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['last_viewed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['last_viewed']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['last_viewed']['date_format'] = 'long';
  /* Field: Databasics: Visits */
  $handler->display->display_options['fields']['view_count']['id'] = 'view_count';
  $handler->display->display_options['fields']['view_count']['table'] = 'databasics';
  $handler->display->display_options['fields']['view_count']['field'] = 'view_count';
  $handler->display->display_options['fields']['view_count']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_count']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_count']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_count']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_count']['set_precision'] = 0;
  $handler->display->display_options['fields']['view_count']['precision'] = '0';
  $handler->display->display_options['fields']['view_count']['format_plural'] = 0;
  $handler->display->display_options['fields']['view_count']['percent'] = 0;
  /* Field: Databasics: Visits graph */
  $handler->display->display_options['fields']['view_count_percent']['id'] = 'view_count_percent';
  $handler->display->display_options['fields']['view_count_percent']['table'] = 'databasics';
  $handler->display->display_options['fields']['view_count_percent']['field'] = 'view_count_percent';
  $handler->display->display_options['fields']['view_count_percent']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['alter']['external'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_count_percent']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_count_percent']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['view_count_percent']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_count_percent']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_count_percent']['set_precision'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['precision'] = '0';
  $handler->display->display_options['fields']['view_count_percent']['format_plural'] = 0;
  $handler->display->display_options['fields']['view_count_percent']['percent'] = 0;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['uid']['title'] = '%1 has visited the following pages:';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;

  /* Display: Report Page */
  $handler = $view->new_display('page', 'Report Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/databasics';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Databasics Node Visits';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: User Tab Page */
  $handler = $view->new_display('page', 'User Tab Page', 'page_1');
  $handler->display->display_options['path'] = 'user/%/databasics';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Databasics Visits';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
 
 $views[$view->name] = $view;
 
 return $views;
}
