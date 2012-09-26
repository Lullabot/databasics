<?php

class databasics_handler_filter_numeric extends views_handler_filter_numeric {
  function operators() {
    $operators = parent::operators();
    $operators['even'] = array(
      'title' => t('Is an even number'),
      'method' => 'op_even',
      'short' => t('even'),
      'values' => 0,
    );
    return $operators;
  }

  function op_even($field) {
    $this->query->add_where_expression($this->options['group'], 'MOD(' . $field . ', 2) = 0');
  }
}
