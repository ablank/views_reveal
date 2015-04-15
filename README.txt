
Views Reveal
===============

The Views Reveal module is a Views Style Plugin that can be used to output Views fields in a Reveal.js presentation.

Reveal.js is provided with an MIT License
Copyright (C) 2014 Hakim El Hattab (http://hakim.se)
Demo : http://lab.hakim.se/reveal-js/#/

Requirements
============
## Module Dependencies:

Views 3 (https://www.drupal.org/project/views)

Libraries 2 (https://www.drupal.org/project/libraries)

Draggable Views (https://www.drupal.org/project/draggableviews)

Reveal.js (https://github.com/ablank/reveal.js || https://github.com/hakimel/reveal.js)


Description
===========

This style plugin will create a View that displays content as a Reveal.js
presentation with a drag & drop admin interface for easy ordering of slides.

Reveal settings are available through the Views Format : Settings.

## Basic Setup

Extract the Reveal.js library to $base_url/sites/all(OR sitename)/libraries/reveal

Enable the Views Reveal module and its dependencies (Libraries, Views, DraggableViews).

Navigate to /admin/structure/views/view/reveal_presentation/edit and add/edit/remove parameters.

-OR-

## Setup from Scratch

Create a new View Page display:

Page title: Title of your presentation

Path: Whatever

Display format: [Reveal Presentation] of [fields] [without links] [without comments]- I prefer these settings and adding fields as needed, but you can really use whatever content display you like, as long as it is a [Reveal Presentation]

Items to display: NULL (as in leave empty - this will display all items)

Do not Use a pager

At this point the presentation is basically functional. Save & exit or Continue & edit the View.

Filter the content by whatever criteria you like- taxonomy terms are an easy way to flag content for inclusion in the presentation, but you can use whatever filtering method you prefer (Contextual, Content type, etc.) to include content in the presentation.

The content preview is useful for seeing the content that will be displayed, but to view the presentation you must navigate to the page path.

Change the FORMAT Settings (set the theme, transitions, etc.) of the Reveal Presentation. Or don't if you like the default settings- do what you want, it's your show =)

Your site theme may interfere with the reveal.js presentation style. If that happens check the styles and override them as needed.

After the content has been filtered and formatted, You should probably Save the View ...

Navigate to the page path to view your presentation. Present. Enjoy!