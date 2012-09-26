<?php

/**
 * Access plugin that provides access control based on ownership.
 */
class databasics_plugin_access extends views_plugin_access {
  // Defines the access callback and arguments to check access or not.
  // If it returns TRUE, we have access, if not, no access.
  function get_access_callback() {
    return array('databasics_check_access', array(array_filter($this->options['restrictions'])));
  }
  
  // Defines options for our access control.
  function option_definition() {
    $options = parent::option_definition();
    $options['restrictions'] = array('default' => array());

    return $options;
  }
  
  // Provides the options form for our settings for restricting access.
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['restrictions'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Which users should have access?'),
      '#default_value' => $this->options['restrictions'],
      '#options' => array(
        'owner' => 'Users who own the user account',
        'reports' => 'Users with "access site reports" permission',
      ),
      '#description' => t('Only users that meet the checked permission will be able to access this display. Note that users with "access all views" can see any view, regardless of permissions or ownership.'),
    );
  }
  
  // Validates the options form to ensure a selection is made.
  function options_validate(&$form, &$form_state) {
    if (!array_filter($form_state['values']['access_options']['restrictions'])) {
      form_error($form['restrictions'], t('You must select at least one restriction if type is "by restriction"'));
    }
  }

  // Submits the options selected.
  function options_submit(&$form, &$form_state) {
    $form_state['values']['access_options']['restrictions'] = array_filter($form_state['values']['access_options']['restrictions']);
  }
  
  // Returns a string to display as the clickable title for this
  // access control.
  function summary_title() {
    // See how many options we have selected.
    $count = count($this->options['restrictions']);
    // None.
    if ($count < 1) {
      return t('No restriction(s) selected');
    }
    // More than 1 option.
    elseif ($count > 1) {
      return t('Multiple restrictions');
    }
    // Only 1 option.
    else {
      $option = reset($this->options['restrictions']);
      return check_plain($option);
    }
  }
}







