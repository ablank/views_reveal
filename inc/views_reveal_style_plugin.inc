<?php
/**
 * @file
 * Configuration of Reveal.js style plugin.
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
  public function option_definition() {
    $options = parent::option_definition();

    $options['width'] = array('default' => '100%');
    $options['height'] = array('default' => '100%');
    $options['margin'] = array('default' => 0.2);
    $options['minScale'] = array('default' => 1.0);
    $options['maxScale'] = array('default' => 1.0);

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
    /*
      // Reveal.js dependencies.
      $options['classList'] = array('default' => TRUE);
      $options['markdown'] = array('default' => TRUE);
      $options['highlight'] = array('default' => TRUE);
      $options['zoom'] = array('default' => TRUE);
      $options['notes'] = array('default' => TRUE);
      $options['remotes'] = array('default' => TRUE);
      $options['math'] = array('default' => TRUE);
     */
    return $options;
  }

  /**
   * Views Reveal options form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $options = views_reveal_get_settings($this->options);
    // Number of options to provide in count-based options.
    $range = drupal_map_assoc(range(1, 10));
    $bool = array(
      1 => t('True'),
      0 => t('False'),
    );
    $percent = drupal_map_assoc(array(
      '10%',
      '20%',
      '30%',
      '40%',
      '50%',
      '60%',
      '70%',
      '80%',
      '90%',
      '100%',
    ));
    $scale = drupal_map_assoc(array(
      0.1,
      0.2,
      0.3,
      0.4,
      0.5,
      0.6,
      0.7,
      0.8,
      0.9,
      1.0,
    ));

    /*
      $form['display'] = array(
      '#type' => 'fieldset',
      '#title' => t('Display Options'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      ); */

    $form['display']['theme'] = array(
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

    $form['display']['width'] = array(
      '#type' => 'select',
      '#title' => t('Width'),
      '#default_value' => $options['width'],
      '#options' => $percent,
      '#description' => t('The "normal" size of the presentation, aspect ratio will be preserved when the presentation is scaled to fit different resolutions.'),
    );

    $form['display']['height'] = array(
      '#type' => 'select',
      '#title' => t('Height'),
      '#default_value' => $options['height'],
      '#options' => $percent,
      '#description' => t('The "normal" size of the presentation, aspect ratio will be preserved when the presentation is scaled to fit different resolutions.'),
    );

    $form['display']['margin'] = array(
      '#type' => 'select',
      '#title' => t('Margin'),
      '#default_value' => $options['margin'],
      '#options' => $scale,
      '#description' => t('Slide margin from window bounds.'),
    );

    $form['display']['minScale'] = array(
      '#type' => 'select',
      '#title' => t('Minimum Scale'),
      '#default_value' => $options['minScale'],
      '#options' => $scale,
      '#description' => t('Bounds for the smallest possible scale to apply to content.'),
    );

    $form['display']['maxScale'] = array(
      '#type' => 'select',
      '#title' => t('Maximum Scale'),
      '#default_value' => $options['maxScale'],
      '#options' => $scale,
      '#description' => t('Bounds for the largest possible scale to apply to content.'),
    );

    $form['display']['controls'] = array(
      '#type' => 'radios',
      '#title' => t('Controls'),
      '#default_value' => $options['controls'],
      '#options' => $bool,
      '#description' => t('Display controls in the bottom right corner.'),
    );

    $form['display']['progress'] = array(
      '#type' => 'radios',
      '#title' => t('Progress'),
      '#default_value' => $options['progress'],
      '#options' => $bool,
      '#description' => t('Display a presentation progress bar.'),
    );

    $form['display']['slideNumber'] = array(
      '#type' => 'radios',
      '#title' => t('Slide Number'),
      '#default_value' => $options['slideNumber'],
      '#options' => $bool,
      '#description' => t('Display the page number of the current slide.'),
    );
    $form['display']['overview'] = array(
      '#type' => 'radios',
      '#title' => t('Overview'),
      '#default_value' => $options['overview'],
      '#options' => $bool,
      '#description' => t('Enable the slide overview mode.'),
    );

    $form['display']['fragments'] = array(
      '#type' => 'radios',
      '#title' => t('Fragments'),
      '#default_value' => $options['fragments'],
      '#options' => $bool,
      '#description' => t('Turns fragments on and off globally.'),
    );

    $form['display']['embedded'] = array(
      '#type' => 'radios',
      '#title' => t('Embedded'),
      '#default_value' => $options['embedded'],
      '#options' => $bool,
      '#description' => t('Flags if the presentation is running in an embedded mode, i.e. contained within a limited portion of the screen.'),
    );

    $form['display']['hideAddressBar'] = array(
      '#type' => 'radios',
      '#title' => t('Hide Address Bar'),
      '#default_value' => $options['hideAddressBar'],
      '#options' => $bool,
      '#description' => t('Hides the address bar on mobile devices.'),
    );
    $form['display']['transition'] = array(
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
    );

    $form['display']['transitionSpeed'] = array(
      '#type' => 'textfield',
      '#title' => t('Transition Speed'),
      '#default_value' => $options['transitionSpeed'],
      '#options' => array(
        'default' => t('Default'),
        'fast' => t('Fast'),
        'slow' => t('Slow'),
      ),
    );

    $form['display']['backgroundTransition'] = array(
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
      '#description' => t('Transition style for full page slide backgrounds.'),
    );

    $form['display']['viewDistance'] = array(
      '#type' => 'select',
      '#title' => t('View Distance'),
      '#default_value' => $options['viewDistance'],
      '#options' => $range,
      '#description' => t('Number of slides away from the current that are visible.'),
    );

    $form['display']['parallaxBackgroundImage'] = array(
      '#type' => 'textfield',
      '#title' => t('Parallax Background Image'),
      '#default_value' => $options['parallaxBackgroundImage'],
      '#description' => 'e.g. "https://s3.amazonaws.com/hakim-static/reveal-js/reveal-parallax-1.jpg"',
    );

    $form['display']['parallaxBackgroundSize'] = array(
      '#type' => 'textfield',
      '#title' => t('Parallax Background Size'),
      '#default_value' => $options['parallaxBackgroundSize'],
      '#description' => t('Parallax background size, CSS syntax, e.g. "2100px 900px"'),
    );

    /*
      $form['control'] = array(
      '#type' => 'fieldset',
      '#title' => t('Control Options'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      ); */

    $form['control']['history'] = array(
      '#type' => 'radios',
      '#title' => t('History'),
      '#default_value' => $options['history'],
      '#options' => $bool,
      '#description' => t('Push each slide change to the browser history.'),
    );

    $form['control']['keyboard'] = array(
      '#type' => 'radios',
      '#title' => t('Keyboard'),
      '#default_value' => $options['keyboard'],
      '#options' => $bool,
      '#description' => t('Enable keyboard shortcuts for navigation.'),
    );

    $form['control']['center'] = array(
      '#type' => 'radios',
      '#title' => t('Center'),
      '#default_value' => $options['center'],
      '#options' => $bool,
      '#description' => t('Vertical centering of slides.'),
    );

    $form['control']['touch'] = array(
      '#type' => 'radios',
      '#title' => t('Touch'),
      '#default_value' => $options['touch'],
      '#options' => $bool,
      '#description' => t('Enables touch navigation on devices with touch input.'),
    );

    $form['control']['loop'] = array(
      '#type' => 'radios',
      '#title' => t('Loop'),
      '#default_value' => $options['loop'],
      '#options' => $bool,
      '#description' => t('Loop the presentation.'),
    );

    $form['control']['rtl'] = array(
      '#type' => 'radios',
      '#title' => t('RTL'),
      '#default_value' => $options['rtl'],
      '#options' => $bool,
      '#description' => t('Change the presentation direction to be RTL.'),
    );

    $form['control']['previewLinks'] = array(
      '#type' => 'radios',
      '#title' => t('Preview Links'),
      '#default_value' => $options['previewLinks'],
      '#options' => $bool,
      '#description' => t('Opens links in an iframe preview overlay.'),
    );

    $form['control']['autoSlide'] = array(
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
      '#description' => t('Number of milliseconds between automatically proceeding to the next slide, disabled when set to 0, this value can be overwritten by using a data-autoslide attribute on your slides'),
    );

    $form['control']['autoSlideStoppable'] = array(
      '#type' => 'radios',
      '#title' => t('AutoSlide Stoppable'),
      '#default_value' => $options['autoSlideStoppable'],
      '#options' => $bool,
      '#description' => t('Stop auto-sliding after user input.'),
    );

    $form['control']['mousewheel'] = array(
      '#type' => 'radios',
      '#title' => t('Mousewheel'),
      '#default_value' => $options['mousewheel'],
      '#options' => $bool,
      '#description' => t('Enable slide navigation via mouse wheel.'),
    );

    /*
      $form['plugins'] = array(
      '#type' => 'fieldset',
      '#title' => t('Plugins'),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      ); */

    $form['plugins']['classList'] = array(
      '#type' => 'radios',
      '#title' => 'ClassList',
      '#default_value' => $options['classList'],
      '#options' => $bool,
      '#description' => t('Cross-browser shim that fully implements classList.'),
    );

    $form['plugins']['markdown'] = array(
      '#type' => 'radios',
      '#title' => 'Markdown',
      '#default_value' => $options['markdown'],
      '#options' => $bool,
      '#description' => t('Interpret Markdown in <section> elements.'),
    );

    $form['plugins']['highlight'] = array(
      '#type' => 'radios',
      '#title' => 'Highlight',
      '#default_value' => $options['highlight'],
      '#options' => $bool,
      '#description' => t('Syntax highlight for &lt;code&gt; elements.'),
    );

    $form['plugins']['zoom'] = array(
      '#type' => 'radios',
      '#title' => 'Zoom',
      '#default_value' => $options['zoom'],
      '#options' => $bool,
      '#description' => t('Zoom in and out with Alt+click.'),
    );

    $form['plugins']['notes'] = array(
      '#type' => 'radios',
      '#title' => 'Notes',
      '#default_value' => $options['notes'],
      '#options' => $bool,
      '#description' => t('Speaker notes.'),
    );

    $form['plugins']['remotes'] = array(
      '#type' => 'radios',
      '#title' => 'Remotes',
      '#default_value' => $options['remotes'],
      '#options' => $bool,
      '#description' => t('Remote control your reveal.js presentation using a touch device.'),
    );

    $form['plugins']['math'] = array(
      '#type' => 'radios',
      '#title' => 'MathJax',
      '#default_value' => $options['math'],
      '#options' => $bool,
    );
  }

}
