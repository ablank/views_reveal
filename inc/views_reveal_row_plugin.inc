w<?php
/**
 * @file
 * Contains the Reveal.js style plugin.
 */

/**
 * Style plugin to render rows as slides in a Reveal.js presentation.
 *
 * @ingroup views_style_plugins
 */
class views_reveal_row_plugin extends views_plugin_row {

  /**
   * Views Reveal settings.
   */
  function options(&$options) {
    $options = parent::options($options);

    $options['theme'] = array('default' => 'default');
  }

  /**
   * Views Reveal settings form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Number of options to provide in count-based options.
    $range = drupal_map_assoc(range(1, 10));
    $auto_range = array('' => t('Auto')) + $range;
    $bool = array(
      TRUE => t('True'),
      FALSE => t('False'),
    );
    $themes = array();

    $form['theme'] = array(
      '#type' => 'select',
      '#title' => t('Theme'),
      '#default_value' => $this->options['theme'],
      '#options' => $themes,
      '#description' => t('Set to "None" if your theme includes custom styles directly '),
    );
  }

}
