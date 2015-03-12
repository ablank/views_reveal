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
    $options['margin'] = array('default' => 1.0);
    $options['minScale'] = array('default' => 0.2);
    $options['maxScale'] = array('default' => 1.0);

    $options['theme'] = array('default' => 'default');
    $options['controls'] = array('default' => 1);
    $options['progress'] = array('default' => 1);
    $options['slideNumber'] = array('default' => 0);
    $options['history'] = array('default' => 0);
    $options['keyboard'] = array('default' => 1);
    $options['overview'] = array('default' => 1);
    $options['center'] = array('default' => 1);
    $options['touch'] = array('default' => 1);
    $options['loop'] = array('default' => 0);
    $options['rtl'] = array('default' => 0);
    $options['fragments'] = array('default' => 1);
    $options['embedded'] = array('default' => 0);
    $options['autoSlide'] = array('default' => 0);
    $options['autoSlideStoppable'] = array('default' => 1);
    $options['mousewheel'] = array('default' => 0);
    $options['hideAddressBar'] = array('default' => 1);
    $options['previewLinks'] = array('default' => 0);
    $options['transition'] = array('default' => 'default');
    $options['transitionSpeed'] = array('default' => 'default');
    $options['backgroundTransition'] = array('default' => 'default');
    $options['viewDistance'] = array('default' => 3);
    $options['parallaxBackgroundImage'] = array('default' => '');
    $options['parallaxBackgroundSize'] = array('default' => '');

    // Reveal.js plugins.
    $options['highlight'] = array('default' => 1);
    $options['leap'] = array('default' => 0);
    $options['markdown'] = array('default' => 1);
    $options['math'] = array('default' => 0);
    $options['notes'] = array('default' => 0);
    $options['remotes'] = array('default' => 0);
    $options['search'] = array('default' => 0);
    $options['zoom'] = array('default' => 1);

    return $options;
  }

  /**
   * Views Reveal options form.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $options = views_reveal_get_settings($this->options);
    /**/
    $range = drupal_map_assoc(range(1.0, 10.0));
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
    /**/

    $form['display'] = array(
      '#type' => 'fieldset',
      '#title' => t('Display Options'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['display']['theme'] = array(
      '#type' => 'select',
      '#title' => t('Theme'),
      '#default_value' => $options['theme'],
      '#options' => array(
        0 => t('None'),
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
      '#type' => 'select',
      '#title' => t('Transition Speed'),
      '#default_value' => $options['transitionSpeed'],
      '#options' => array(
        'default' => t('Default'),
        'fast' => t('Fast'),
        'slow' => t('Slow'),
      ),
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
      '#options' => $range,
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

    $form['display']['progress'] = array(
      '#type' => 'radios',
      '#title' => t('Progress'),
      '#options' => $bool,
      '#default_value' => isset($options['progress']) ? $options['progress'] : NULL,
      '#description' => t('Display a presentation progress bar.'),
    );

    $form['display']['slideNumber'] = array(
      '#type' => 'radios',
      '#title' => t('Slide Number'),
      '#default_value' => $options['slideNumber'],
      '#options' => $bool,
      '#description' => t('Display the page number of the current slide.'),
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

    $form['control'] = array(
      '#type' => 'fieldset',
      '#title' => t('Control Options'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['control']['controls'] = array(
      '#type' => 'radios',
      '#title' => t('Controls'),
      '#default_value' => $options['controls'],
      '#options' => $bool,
      '#description' => t('Display controls in the bottom right corner.'),
    );

    $form['control']['fragments'] = array(
      '#type' => 'radios',
      '#title' => t('Fragments'),
      '#default_value' => $options['fragments'],
      '#options' => $bool,
      '#description' => t('Turns fragments on and off globally.'),
    );

    $form['control']['embedded'] = array(
      '#type' => 'radios',
      '#title' => t('Embedded'),
      '#default_value' => $options['embedded'],
      '#options' => $bool,
      '#description' => t('Flags if the presentation is running in an embedded mode, i.e. contained within a limited portion of the screen.'),
    );

    $form['control']['hideAddressBar'] = array(
      '#type' => 'radios',
      '#title' => t('Hide Address Bar'),
      '#default_value' => $options['hideAddressBar'],
      '#options' => $bool,
      '#description' => t('Hides the address bar on mobile devices.'),
    );

    $form['control']['overview'] = array(
      '#type' => 'radios',
      '#title' => t('Overview'),
      '#default_value' => $options['overview'],
      '#options' => $bool,
      '#description' => t('Enable the slide overview mode.'),
    );

    $form['control']['viewDistance'] = array(
      '#type' => 'select',
      '#title' => t('View Distance'),
      '#default_value' => $options['viewDistance'],
      '#options' => $range,
      '#description' => t('Number of slides away from the current that are visible.'),
    );

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
        0 => 'Disabled',
        10000 => '10 seconds',
        20000 => '20 seconds',
        30000 => '30 seconds',
        60000 => '1 minute',
        120000 => '2 minutes',
        180000 => '3 minutes',
        240000 => '4 minutes',
        300000 => '5 minutes',
        600000 => '10 minutes',
      ),
      '#default_value' => $options['autoSlide'],
      '#description' => t('Number of seconds between automatically proceeding to the next slide, disabled when set to 0, this value can be overwritten by using a data-autoslide attribute on your slides'),
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

    $form['plugins'] = array(
      '#type' => 'fieldset',
      '#title' => t('Plugins'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
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

    $form['plugins']['search'] = array(
      '#type' => 'radios',
      '#title' => 'Search',
      '#default_value' => $options['search'],
      '#options' => $bool,
      '#description' => t('Find a text string anywhere in the slides.'),
    );

    $form['plugins']['zoom'] = array(
      '#type' => 'radios',
      '#title' => 'Zoom',
      '#default_value' => $options['zoom'],
      '#options' => $bool,
      '#description' => t('Zoom in and out with Alt+click.'),
    );

    $form['plugins']['leap'] = array(
      '#type' => 'radios',
      '#title' => 'Leap Motion',
      '#default_value' => $options['leap'],
      '#options' => $bool,
      '#description' => t('Utilize your Leap Motion device to control basic navigation of your presentation.'),
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
