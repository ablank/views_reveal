Reveal.js presentations are awesome.

Drupal Views is awesome.

Draggable Views is awesome

Views_Reveal is awesome<sup>3</sup>

Easily create reveal.js presentations from content in a drupal database, style the presentation using settings in the Views UI, and arrange slides with a drag & drop interface.

##Create a Reveal.js Presentation using Views fields.

###Requirements
- [Libraries](https://www.drupal.org/project/libraries)
- [Views](https://www.drupal.org/project/views)
- [Draggable Views](https://www.drupal.org/project/draggableviews)
- [Reveal.js](https://github.com/ablank/reveal.js) || (https://github.com/hakimel/reveal.js)

### Basic Setup

1. Extract the Reveal.js library to $base_url/sites/all(OR sitename)/libraries/reveal
2. Enable the Views Reveal module and its dependencies (Libraries, Views, DraggableViews).
3. Navigate to `/admin/structure/views/view/reveal_presentation/edit` and add/edit/remove parameters.

## -OR-

### Setup from Scratch

1. Create a new View Page display:
- Page title: Title of your presentation

- Path: Whatever

- Display format: [Reveal Presentation] of [fields] [without links] [without comments]- 
I prefer these settings and adding fields as needed, but you can really use 
whatever content display you like, as long as it is a [Reveal Presentation]

- Items to display: NULL (as in leave empty - this will display all items)

- *Do not* Use a pager

- At this point the presentation is basically functional.
Save & exit or Continue & edit the View.

2. Filter the content by whatever criteria you like- taxonomy terms are an easy
way to flag content for inclusion in the presentation, but you can use whatever
filtering method you prefer (Contextual, Content type, etc.) to include content
in the presentation.

- The content preview is useful for seeing the content that will be displayed,
but to view the presentation you must navigate to the page path.

3. Change the FORMAT Settings (set the theme, transitions, etc.) of the Reveal
Presentation. Or don't if you like the default settings- do what you want, it's
your show =)

- Your site theme may interfere with the reveal.js presentation style. If that
happens check the <body> styles and override them as needed.

4. After the content has been filtered and formatted, You should probably Save
the View ...

5. Navigate to the page path to view your presentation. Present. Enjoy!
