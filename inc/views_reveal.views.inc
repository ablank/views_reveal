<?php
/**
 * @file
 * Views integration for Views Reveal module.
 */

/**
 * Implements hook_views_plugins().
 */
function views_reveal_views_plugins() {
  $inc = drupal_get_path('module', 'views_reveal') . '/inc';

  $plugin['style']['reveal'] = array(
    'title' => t('Reveal Presentation'),
    'handler' => 'views_reveal_style_plugin',
    'path' => $inc,
    'theme' => 'views_view_reveal',
    'theme path' => $inc,
    'help' => t('Display fields as a Reveal.js presentation.'),
    'uses options' => TRUE,
    'uses row plugin' => TRUE,
    'uses row class' => FALSE,
    'uses grouping' => FALSE,
    'type' => 'normal',
  );
  
  return $plugin;
}
