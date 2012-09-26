<?php

class databasics_handler_sort_custom extends views_handler_sort {
  function query() {
    global $user;
    // ORDER BY FIELD(uid, 1) DESC, uid ASC/DESC
    $field = 'FIELD(' . $this->table . '.' . $this->field . ',' . $user->uid . ')';
    $this->query->add_orderby(NULL, $field, 'DESC');
    $this->query->add_orderby(NULL, $this->table . '.' . $this->field, $this->options['order']);
  }
}
