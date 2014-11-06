<?php
/**
 * @file views_reveal-view.tpl.php
 * View template to display reveal.js presentation.
 */
?>

<div class="reveal <?php print $classes; ?>">
  <div class="slides">
      <?php foreach ($rows as  $row_id => $row) : ?>
        <section>
          <?php print $row; ?>
        </section>
      <?php endforeach; ?>
  </div>
</div>
