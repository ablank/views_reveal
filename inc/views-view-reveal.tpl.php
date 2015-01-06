<?php
/**
 * @file
 * View template to display reveal.js presentation.
 */

?>

<div class="<?php print $classes; ?>">
  <div class="slides<?php
      if (!empty($draggable)):
        print " $draggable";
      endif; ?>">

    <?php foreach ($rows as $row_id => $row) : ?>
      
      <section>
        <?php print $row; ?>
      </section>
    <?php endforeach; ?>
  </div>
</div>
