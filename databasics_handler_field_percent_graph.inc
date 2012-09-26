<?php

class databasics_handler_field_percent_graph extends databasics_handler_field_percent {
  function render($values) {
    $value = $this->get_value($values);
    return '<div class="databasics-graph" style="display:block; background: #000; height: 10px; width: ' . $value . '%;">' . $value . '</div>';
  }
}