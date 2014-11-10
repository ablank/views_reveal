//jQuery.noConflict();
(function ($) {
  Drupal.behaviors.views_reveal = {
    attach: function (context, settings) {
      var vr = Drupal.settings.views_reveal;
      console.log(vr);
      Reveal.initialize({
        /**/
        dependencies: [
          // Cross-browser shim that fully implements classList - https://github.com/eligrey/classList.js/
          {
            src: vr.lib + '/lib/js/classList.js',
            condition: function () {
              return !document.body.classList;
            }}
        ],
        //// The "normal" size of the presentation, aspect ratio will be preserved
        // when the presentation is scaled to fit different resolutions. Can be
        // specified using percentage units.
        width: vr.width,
        height: vr.height,
        // Factor of the display size that should remain empty around the content
        margin: parseFloat(vr.margin),
        // Bounds for smallest/largest possible scale to apply to content
        minScale: parseFloat(vr.minScale),
        maxScale: parseFloat(vr.maxScale),
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
        // by using a data-autoslide attribute on your slides
        autoSlide: vr.autoSlide,
        // Stop auto-sliding after user input
        autoSlideStoppable: vr.autoSlideStoppable,
        // Enable slide navigation via mouse wheel
        mouseWheel: vr.mouseWheel,
        // Hides the address bar on mobile devices
        hideAddressBar: vr.hideAddressBar,
        // Opens links in an iframe preview overlay
        previewLinks: vr.previewLinks,
        // Transition style
        transition: vr.transition, // default/cube/page/concave/zoom/linear/fade/none

        // Transition speed
        transitionSpeed: vr.transitionSpeed, // default/fast/slow

        // Transition style for full page slide backgrounds
        backgroundTransition: vr.backgroundTransition, // default/none/slide/concave/convex/zoom

        // Number of slides away from the current that are visible
        viewDistance: vr.viewDistance,
        // Parallax background image
        parallaxBackgroundImage: vr.parallaxBackgroundImage, // e.g. "'https://s3.amazonawsettings.com/hakim-static/reveal-js/reveal-parallax-1.jpg'"

        // Parallax background size
        parallaxBackgroundSize: vr.parallaxBackgroundSize // CSS syntax, e.g. "2100px 900px"
      });
      
    }
  };
})(jQuery);
