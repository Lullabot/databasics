<?php
/**
 * @file
 */
class databasics_handler_area_databasics extends views_handler_area {
  function render($empty = FALSE) {
    dsm($this);
    // Must have the count in order for this to work.
    if (!isset($this->view->field['view_count'])) {
      return;
    }

    $total = 0;
    $count_field =  $this->view->field['view_count']->field_alias;
    foreach ($this->view->result as $row) {
      $total = $total + $row->{$count_field};
    }
    // This is only a total for the rows displayed on this page. Keep that
    // in mind. It is not a total of all view counts for this node.  You could
    // however do that using the same query we used in our percent handler.
    return t('Total views shown: @total.', array('@total' => $total));
  }
}
