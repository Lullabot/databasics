The databasics module contains 4 different branches which each represent the module in different states of completion.

*databasics-start*

Includes a .install to create a databasics table and demonstrates use of hook_schema(), hook_install() and hook_uninstall().

*databasics-complete*

Includes updates to add a new column to 'last_viewed' to the database table. Demonstrates use of hook_update_N() to update your schema.

*databasics-views*

Includes views integration for the databasics table. Demonstrates describing your table to views and using default/exported views as a means to display the statastics table provided by the module. Used for example to replace the previously hard coded table at user/%user/databasics

*databasics-test*

Adds a .test file. Demonstrates the use SimpleTest by testing that the "This page has been viewed X times" appears on the appropriate pages.