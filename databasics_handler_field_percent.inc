<?php

class databasics_handler_field_percent extends views_handler_field_numeric {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
    $this->definition['float'] = TRUE;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['percent'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display as percent'),
      '#descritpion' => t('If checked display the number as percent of total views of this node by all users.'),
      '#default_value' => $this->options['percent'],
    );
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['percent'] = array('default' => FALSE);
    return $options;
  }

  function query() {
    parent::query();
    if ($this->options['percent']) {
      $this->add_additional_fields();
    }
  }

  function pre_render(&$values) {
    parent::pre_render($values);
    if ($this->options['percent']) {
      foreach($values as $key => $row) {
        $nid = $row->{$this->aliases['nid']};
        $total = db_query('SELECT SUM(view_count) FROM {databasics} WHERE nid = :nid', array(':nid' => $nid))->fetchField();
        $count = $this->get_value($row);
        $percentage = ($count / $total) * 100;
        $values[$key]->{$this->field_alias} = $percentage;
      }
    }
  }

}
