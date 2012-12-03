The databasics module contains 5 different branches which each represent the module in different states of completion. If you are teaching this lesson as a part of the Module Development course, you'll typically want to skip databasics-capn and go straight to databasics-start.

*databasics-capn*
Basically just capn module, if you want to start completely from scratch and show how we're moving to a database storage for the same functionality.

*databasics-start*

Includes a .install to create a databasics table and demonstrates use of hook_schema(), hook_install() and hook_uninstall().

*databasics-complete*

Includes updates to add a new column to 'last_viewed' to the database table. Demonstrates use of hook_update_N() to update your schema.

*databasics-views*

Includes views integration for the databasics table. Demonstrates describing your table to views and using default/exported views as a means to display the statastics table provided by the module. Used for example to replace the previously hard coded table at user/%user/databasics

*databasics-test*

Adds a .test file. Demonstrates the use SimpleTest by testing that the "This page has been viewed X times" appears on the appropriate pages.

*databasics-drush*

Adds a databasics.drush.inc command file and a basic drush command for generating random databasics records. Demonstrates the use of most of the basic drush API's.
