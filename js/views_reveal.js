(function ($) {
  Drupal.behaviors.views_reveal = {
    attach: function (context, settings) {
      var s = Drupal.settings.views_reveal;
      console.log(s);
      Reveal.initialize({
        // Display controls in the bottom right corner
        controls: s.controls,
        // Display a presentation progress bar
        progress: s.progress,
        // Display the page number of the current slide
        slideNumber: s.slideNumber,
        // Push each slide change to the browser history
        history: s.history,
        // Enable keyboard shortcuts for navigation
        keyboard: s.keyboard,
        // Enable the slide overview mode
        overview: s.overview,
        // Vertical centering of slides
        center: s.center,
        // Enables touch navigation on devices with touch input
        touch: s.touch,
        // Loop the presentation
        loop: s.loop,
        // Change the presentation direction to be RTL
        rtl: s.rtl,
        // Turns fragments on and off globally
        fragments: s.fragments,
        // Flags if the presentation is running in an embedded mode,
        // i.e. contained within a limited portion of the screen
        embedded: s.embedded,
        // Number of milliseconds between automatically proceeding to the
        // next slide, disabled when set to 0, this value can be overwritten
        // by using a data-autoslide attribute on your slides
        autoSlide: s.autoSlide,
        // Stop auto-sliding after user input
        autoSlideStoppable: s.autoSlideStoppable,
        // Enable slide navigation via mouse wheel
        mouseWheel: s.mouseWheel,
        // Hides the address bar on mobile devices
        hideAddressBar: s.hideAddressBar,
        // Opens links in an iframe preview overlay
        previewLinks: s.previewLinks,
        // Transition style
        transition: s.transition, // default/cube/page/concave/zoom/linear/fade/none

        // Transition speed
        transitionSpeed: s.transitionSpeed, // default/fast/slow

        // Transition style for full page slide backgrounds
        backgroundTransition: s.backgroundTransition, // default/none/slide/concave/convex/zoom

        // Number of slides away from the current that are visible
        viewDistance: s.viewDistance,
        // Parallax background image
        parallaxBackgroundImage: s.parallaxBackgroundImage, // e.g. "'https://s3.amazonaws.com/hakim-static/reveal-js/reveal-parallax-1.jpg'"

        // Parallax background size
        parallaxBackgroundSize: s.parallaxBackgroundSize // CSS syntax, e.g. "2100px 900px"
      });
    }
  };
})(jQuery);