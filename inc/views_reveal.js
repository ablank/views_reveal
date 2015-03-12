/**
 * @file
 * JS initialization for Views_Reveal.
 */

(function ($) {
  Drupal.behaviors.views_reveal = {
    attach: function (context, settings) {
      var vr = JSON.parse(Drupal.settings.views_reveal);
      var depends = [
        {
          src: vr.lib + '/lib/js/html5shiv.js'
        },
        {
          src: vr.lib + '/lib/js/classList.js'
        }
      ];

      if (vr.markdown === true) {
        depends.push({
          src: vr.lib + '/plugin/markdown/marked.js',
          condition: function () {
            return !!document.querySelector('[data-markdown]');
          }
        },
        {
          src: vr.lib + '/plugin/markdown/markdown.js',
          condition: function () {
            return !!document.querySelector('[data-markdown]');
          }
        });
      }
      if (vr.zoom === true) {
        depends.push({
          src: vr.lib + '/plugin/zoom-js/zoom.js',
          async: true,
          condition: function () {
            return !!document.body.classList;
          }
        });
      }
      if (vr.notes === true) {
        depends.push({
          src: vr.lib + '/plugin/notes/notes.js',
          async: true,
          condition: function () {
            return !!document.body.classList;
          }
        });
      }
      if (vr.remotes === true) {
        depends.push({
          src: vr.lib + '/plugin/remotes/remotes.js',
          async: true,
          condition: function () {
            return !!document.body.classList;
          }
        });
      }
      if (vr.highlight === true) {
        depends.push({
          src:  vr.lib + '/plugin/highlight/highlight.js',
          async: true,
          callback: function () {
            hljs.initHighlightingOnLoad();
          }
        });
      }
      if (vr.search === true) {
        depends.push({
          src:  vr.lib + '/plugin/search/search.js',
          async: true
        });
      }
      if (vr.leap === true) {
        depends.push({
          src:  vr.lib + '/plugin/leap/leap.js',
          async: true
        });
      }
      if (vr.math === true) {
        depends.push({
          src: vr.lib + '/plugin/math/math.js',
          async: true
        });
      }

      Reveal.initialize({
        dependencies: depends,
        // The "normal" size of the presentation, aspect ratio will be preserved
        // when the presentation is scaled to fit different resolutions. Can be
        // specified using percentage units.
        width: vr.width,
        height: vr.height,
        // Factor of the display size that should remain empty around the content.
        margin: vr.margin,
        // Bounds for smallest/largest possible scale to apply to content.
        minScale: vr.minScale,
        maxScale: vr.maxScale,
        // Display controls in the bottom right corner.
        controls: vr.controls,
        // Display a presentation progress bar.
        progress: vr.progress,
        // Display the page number of the current slide.
        slideNumber: vr.slideNumber,
        // Push each slide change to the browser history.
        history: vr.history,
        // Enable keyboard shortcuts for navigation.
        keyboard: vr.keyboard,
        // Enable the slide overview mode.
        overview: vr.overview,
        // Vertical centering of slides.
        center: vr.center,
        // Enables touch navigation on devices with touch input.
        touch: vr.touch,
        // Loop the presentation.
        loop: vr.loop,
        // Change the presentation direction to be RTL.
        rtl: vr.rtl,
        // Turns fragments on and off globally.
        fragments: vr.fragments,
        // Flags if the presentation is running in an embedded mode,
        // i.e. contained within a limited portion of the screen.
        embedded: vr.embedded,
        // Number of milliseconds between automatically proceeding to the
        // next slide, disabled when set to 0, this value can be overwritten
        // by using a data-autoslide attribute on your slides.
        autoSlide: vr.autoSlide,
        // Stop auto-sliding after user input.
        autoSlideStoppable: vr.autoSlideStoppable,
        // Enable slide navigation via mouse wheel.
        mouseWheel: vr.mouseWheel,
        // Hides the address bar on mobile devices.
        hideAddressBar: vr.hideAddressBar,
        // Opens links in an iframe preview overlay.
        previewLinks: vr.previewLinks,
        // Transition style (default/cube/page/concave/zoom/linear/fade/none).
        transition: vr.transition,
        // Transition speed (default/fast/slow).
        transitionSpeed: vr.transitionSpeed,
        // Transition style for full page slide backgrounds
        // (default/none/slide/concave/convex/zoom).
        backgroundTransition: vr.backgroundTransition,
        // Number of slides away from the current that are visible.
        // e.g. "'https://s3.amazonawsettings.com/hakim-static/reveal-js/reveal-parallax-1.jpg'".
        viewDistance: vr.viewDistance,
        // Parallax background image.
        parallaxBackgroundImage: vr.parallaxBackgroundImage,
        // Parallax background size using CSS syntax, e.g. "2100px 900px"
        parallaxBackgroundSize: vr.parallaxBackgroundSize
      });

    }
  };
})(jQuery);
