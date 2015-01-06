/**
 * @file
 * Adds draggable functionality to the html list display of the view.
 */

(function ($) {
  Drupal.behaviors.draggableViews = {
    attach: function (context, settings) {
      var view = $('.views-form');
      var vrow = $(view).find(Drupal.settings.draggable_row_class);
      // $('.views-form .' + Drupal.settings.draggable_row_class + ':not(.draggableviews-processed)', context)
      $('.draggableviews').once(vrow, function () {
        console.log(vrow);
        // Add sortable effect.
        $(vrow).sortable({
          update: function (event, ui) {
            $(".draggableviews-weight").each(function (i, Val) {
              $(this).val(i);
            });
            if (!$(this).hasClass('draggableviews-changed')) {
              // If view is not ajaxified.
              if (!Drupal.settings.draggable_ajax) {
                $('<div class="draggableviews-changed-warning messages warning">' + Drupal.t('Changes made in this list will not be saved until the form is submitted.') + '</div>')
                  .insertBefore($(this).parents('form div.item-list')).hide().fadeIn('slow');
                $(this).addClass('draggableviews-changed');
              }
              else {
                // If view ajaxified.
                $('<div class="draggableviews-changed-notice messages warning">' + Drupal.t('Order of the list has been changed.') + '</div>')
                  .insertBefore($(this).parents('form div.item-list')).hide().fadeIn('slow').delay(3000).fadeOut('slow');
                $(this).addClass('draggableviews-changed');
              }
            }
            // If Ajax enabled, submit the form.
            if (Drupal.settings.draggableviews_ajax) {
              $(this).parent().find('#edit-submit').trigger('mousedown');
            }
          },
          containment: 'parent',
          cursor: 'move'
        });
        if (Drupal.settings.draggableviews_ajax) {
          $(vrow).parent().find('#edit-submit').hide();
        }
      });
    }
  }
})(jQuery);
