<?php

/**
 * Render a numeric field as a "written" string.
 */
class databasics_field_numerify extends views_handler_field_numeric {
  // Oh, wow. An actual *class!* With inheritance and everything!
  // We'll piggyback on Views' normal numeric field handler to make
  // things easier for ourselves.

  /**
   * Define the settings unique to this views field handler.
   */
  function option_definition() {
    // First make sure we get the "standard" options defined by our parent class.
    $options = parent::option_definition();

    // Next, define our option and our default value and return the $options.
    $options['numerify'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Define the settings settings form for this field handler's options.
   */
  function options_form(&$form, &$form_state) {
    // First, make sure we include the options for the normal number fields.
    parent::options_form($form, $form_state);

    // If the field is NOT a floating point number, we can numerify it. So add
    // a checkbox that lets users turn on our "Numerify" option.
    if (empty($this->definition['float'])) {
      $form['numerify'] = array(
        '#type' => 'checkbox',
        '#title' => t('Numerify this number'),
        '#description' => t('If checked, the number will be printed as English text instead of numerals.'),
        '#default_value' => $this->options['numerify'],
      );
    }
  }

  /**
   * Render the field's value after it's been pulled from the database.
   */
  function render($values) {
    if (empty($this->options['numerify'])) {
      // If the user DIDN'T choose to numerify this field, we'll let our parent
      // class -- Views' default numeric field -- handle the rendering.
      return parent::render($values);
    }
    else {
      // If we get here, the user DID want to numerify the field. We'll get our
      // value from the list handed to us, and call our helper function to format it.
      $value = (int) $values->{$this->field_alias};
      return $this->numerify($value);
    }
  }

  /**
   * Thar be dragons here. Read not this code! It is full of wrong. But it works!
   * ...For numbers smaller than one million.
   */
  function numerify($no = 0) {
    $words = array(
      '0' => '',
      '1' => 'one',
      '2' => 'two',
      '3' => 'three',
      '4' => 'four',
      '5' => 'five',
      '6' => 'six',
      '7' => 'seven',
      '8' => 'eight',
      '9' => 'nine',
      '10' => 'ten',
      '11' => 'eleven',
      '12' => 'twelve',
      '13' => 'thirteen',
      '14' => 'fouteen',
      '15' => 'fifteen',
      '16' => 'sixteen',
      '17' => 'seventeen',
      '18' => 'eighteen',
      '19' => 'nineteen',
      '20' => 'twenty',
      '30' => 'thirty',
      '40' => 'fourty',
      '50' => 'fifty',
      '60' => 'sixty',
      '70' => 'seventy',
      '80' => 'eighty',
      '90' => 'ninety',
      '100' => 'hundred',
      '1000' => 'thousand',
      '100000' => 'hundred',
    );

    if ($no == 0) {
      return '';
    }
    else {
      $novalue = '';
      $highno = $no;
      $remainno = 0;
      $value = 100;
      $value1 = 1000;
      while ($no >= 100) {
        if (($value <= $no) && ($no < $value1)) {
          $novalue = $words[$value];
          $highno = (int) ($no/$value);
          $remainno = $no % $value;
          break;
        }
        $value = $value1;
        $value1 = $value * 100;
      }
      if (array_key_exists($highno, $words)) {
        return $words[$highno] . " " . $novalue . " " . $this->numerify($remainno);
      }
      else {
        $unit = $highno % 10;
        $ten = (int) ($highno / 10) * 10;
        return $words[$ten] . " " . $words[$unit] . " " . $novalue . " " . $this->numerify($remainno);
      }
    }
  }
}
