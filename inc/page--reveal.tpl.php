<?php
/**
 * @file
 * Reveeal Page Template.
 */

?>
<?php
if ($messages) :
  print $messages;
endif;
// Main Page Content.
print render($page['content']);
