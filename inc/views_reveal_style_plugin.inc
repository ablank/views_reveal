<?php
/**
 * @file
 * Configures the Reveal.js style plugin for Views.
 */

/**
 * Style plugin to render rows as slides in a Reveal.js presentation.
 *
 * @ingroup views_style_plugins
 */
class views_reveal_style_plugin extends views_plugin_style {

  /**
   * Views Reveal options.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['theme'] = array('default' => 'default');
    $options['controls'] = array('default' => TRUE);
    $options['progress'] = array('default' => TRUE);
    $options['slideNumber'] = array('default' => FALSE);
    $options['history'] = array('default' => FALSE);
    $options['keyboard'] = array('default' => TRUE);
    $options['overview'] = array('default' => TRUE);
    $options['center'] = array('default' => TRUE);
    $options['touch'] = array('default' => TRUE);
    $options['loop'] = array('default' => FALSE);
    $options['rtl'] = array('default' => FALSE);
    $options['fragments'] = array('default' => TRUE);
    $options['embedded'] = array('default' => FALSE);
    $options['autoSlide'] = array('default' => 0);
    $options['autoSlideStoppable'] = array('default' => TRUE);
    $options['mousewheel'] = array('default' => FALSE);
    $options['hideAddressBar'] = array('default' => TRUE);
    $options['previewLinks'] = array('default' => FALSE);
    $options['transition'] = array('default' => 'default');
    $options['transitionSpeed'] = array('default' => 'default');
    $options['backgroundTransition'] = array('default' => 'default');
    $options['viewDistance'] = array('default' => 3);
    $options['parallaxBackgroundImage'] = array('default' => '');
    $options['parallaxBackgroundSize'] = array('default' => '');

    return $options;
  }

  /**
   * Views Reveal options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    dpm($this);
    $options = views_reveal_get_settings($this->options);
    // Number of options to provide in count-based options.
    $range = drupal_map_assoc(range(1, 10));
    $bool = array(
      "true" => t('True'),
      "false" => t('False'),
    );

    $form['theme'] = array(
      '#type' => 'select',
      '#title' => t('Theme'),
      '#default_value' => $options['theme'],
      '#options' => array(
        'custom' => t('Custom'),
        'default' => t('Default'),
        'beige' => t('Beige'),
        'blood' => t('Blood'),
        'moon' => t('Moon'),
        'night' => t('Night'),
        'serif' => t('Serif'),
        'simple' => t('Simple'),
        'sky' => t('Sky'),
        'solarized' => t('Solarized'),
      ),
      '#description' => t('Select the theme to use.'),
    );

    $form['controls'] = array(
      '#type' => 'radios',
      '#title' => t('Controls'),
      '#default_value' => $options['controls'],
      '#options' => $bool,
      '#description' => 'Display controls in the bottom right corner.',
    );

    $form['progress'] = array(
      '#type' => 'radios',
      '#title' => t('Progress'),
      '#default_value' => $options['progress'],
      '#options' => $bool,
      '#description' => 'Display a presentation progress bar.',
    );

    $form['slideNumber'] = array(
      '#type' => 'radios',
      '#title' => t('Slide Number'),
      '#default_value' => $options['slideNumber'],
      '#options' => $bool,
      '#description' => 'Display the page number of the current slide.',
    );

    $form['history'] = array(
      '#type' => 'radios',
      '#title' => t('History'),
      '#default_value' => $options['history'],
      '#options' => $bool,
      '#description' => 'Push each slide change to the browser history.',
    );

    $form['keyboard'] = array(
      '#type' => 'radios',
      '#title' => t('Keyboard'),
      '#default_value' => $options['keyboard'],
      '#options' => $bool,
      '#description' => 'Enable keyboard shortcuts for navigation.',
    );

    $form['overview'] = array(
      '#type' => 'radios',
      '#title' => t('Overview'),
      '#default_value' => $options['overview'],
      '#options' => $bool,
      '#description' => 'Enable the slide overview mode.',
    );

    $form['center'] = array(
      '#type' => 'radios',
      '#title' => t('Center'),
      '#default_value' => $options['center'],
      '#options' => $bool,
      '#description' => 'Vertical centering of slides.',
    );

    $form['touch'] = array(
      '#type' => 'radios',
      '#title' => t('Touch'),
      '#default_value' => $options['touch'],
      '#options' => $bool,
      '#description' => 'Enables touch navigation on devices with touch input.',
    );

    $form['loop'] = array(
      '#type' => 'radios',
      '#title' => t('Loop'),
      '#default_value' => $options['loop'],
      '#options' => $bool,
      '#description' => 'Loop the presentation.',
    );

    $form['rtl'] = array(
      '#type' => 'radios',
      '#title' => t('RTL'),
      '#default_value' => $options['rtl'],
      '#options' => $bool,
      '#description' => 'Change the presentation direction to be RTL.',
    );

    $form['fragments'] = array(
      '#type' => 'radios',
      '#title' => t('Fragments'),
      '#default_value' => $options['fragments'],
      '#options' => $bool,
      '#description' => 'Turns fragments on and off globally.',
    );

    $form['embedded'] = array(
      '#type' => 'radios',
      '#title' => t('Embedded'),
      '#default_value' => $options['embedded'],
      '#options' => $bool,
      '#description' => 'Flags if the presentation is running in an embedded mode, i.e. contained within a limited portion of the screen.',
    );

    $form['autoSlide'] = array(
      '#type' => 'select',
      '#title' => t('AutoSlide'),
      '#options' => array(
        0 => 0,
        10000 => 10,
        30000 => 30,
        60000 => 60,
        90000 => 90,
        120000 => 120,
        150000 => 150,
        150000 => 180,
      ),
      '#default_value' => $options['autoSlide'],
      '#description' => 'Number of milliseconds between automatically proceeding to the next slide, disabled when set to 0, this value can be overwritten by using a data-autoslide attribute on your slides',
    );

    $form['autoSlideStoppable'] = array(
      '#type' => 'radios',
      '#title' => t('AutoSlide Stoppable'),
      '#default_value' => $options['autoSlideStoppable'],
      '#options' => $bool,
      '#description' => 'Stop auto-sliding after user input.',
    );

    $form['mousewheel'] = array(
      '#type' => 'radios',
      '#title' => t('Mousewheel'),
      '#default_value' => $options['mousewheel'],
      '#options' => $bool,
      '#description' => 'Enable slide navigation via mouse wheel.',
    );

    $form['hideAddressBar'] = array(
      '#type' => 'radios',
      '#title' => t('Hide Address Bar'),
      '#default_value' => $options['hideAddressBar'],
      '#options' => $bool,
      '#description' => 'Hides the address bar on mobile devices.',
    );

    $form['previewLinks'] = array(
      '#type' => 'radios',
      '#title' => t('Preview Links'),
      '#default_value' => $options['previewLinks'],
      '#options' => $bool,
      '#description' => 'Opens links in an iframe preview overlay.',
    );

    $form['transition'] = array(
      '#type' => 'select',
      '#title' => t('Transition'),
      '#default_value' => $options['transition'],
      '#options' => array(
        'none' => t('None'),
        'default' => t('Default'),
        'cube' => t('Cube'),
        'page' => t('Page'),
        'concave' => t('Concave'),
        'zoom' => t('Zoom'),
        'linear' => t('Linear'),
        'fade' => t('Fade'),
      ),
      '#description' => 'default/cube/page/concave/zoom/linear/fade/none',
    );

    $form['transitionSpeed'] = array(
      '#type' => 'textfield',
      '#title' => t('Transition Speed'),
      '#default_value' => $options['transitionSpeed'],
      '#options' => array(
        'default' => t('Default'),
        'fast' => t('Fast'),
        'slow' => t('Slow'),
      ),
    );

    $form['backgroundTransition'] = array(
      '#type' => 'select',
      '#title' => t('Background Transition'),
      '#default_value' => $options['backgroundTransition'],
      '#options' => array(
        'none' => t('None'),
        'default' => t('Default'),
        'concave' => t('Concave'),
        'convex' => t('Convex'),
        'slide' => t('Slide'),
        'zoom' => t('Zoom'),
      ),
      '#description' => 'Transition style for full page slide backgrounds.',
    );

    $form['viewDistance'] = array(
      '#type' => 'select',
      '#title' => t('View Distance'),
      '#default_value' => $options['viewDistance'],
      '#options' => $range,
      '#description' => 'Number of slides away from the current that are visible.',
    );

    $form['parallaxBackgroundImage'] = array(
      '#type' => 'file',
      '#title' => t('Parallax Background Image'),
      '#default_value' => $options['parallaxBackgroundImage'],
      '#description' => '// e.g. "https://s3.amazonaws.com/hakim-static/reveal-js/reveal-parallax-1.jpg"',
    );

    $form['parallaxBackgroundSize'] = array(
      '#type' => 'radios',
      '#title' => t('Parallax Background Size'),
      '#default_value' => $options['parallaxBackgroundSize'],
      '#description' => 'Parallax background size, CSS syntax, e.g. "2100px 900px"',
    );
  }

}
