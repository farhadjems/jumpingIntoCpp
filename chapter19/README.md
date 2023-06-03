Chapter 19 Practice Problems

1. Write a program that reads in two strings, a "needle" and a "haystack" and counts the number of times the "needle" appears in the "haystack".

2. Write a program that allows a user to type in tabular data similar to a CSV file, but instead of using commas a separator, first prompt the user to enter the separator character, then let the user type in the lines of tabular data. Provide a set of possible punctuation characters as options by looking through the input for non-number, non-letter characters. Find characters that appear on every single line, and choose those characters as the option. For example, if you see input like this:
Alex Allain, webmaster@cprogramming.com
John Smith, john@nowhere.com
You should prompt the user to choose between comma, at sign, and period for the separator.

3. Write a program that reads in HTML text that the user types in (don’t worry, we’ll cover how to read from a file later). It should support the following HTML tags: <html>, <head>, <body>, <b>, <i>, and <a>. Each HTML tag has an open tag, e.g. <html>, and a closing tag which has a forward- slash at the start: </html>. Inside the tag is text that is controlled by that tag: <b>text to be bolded</b> or <i>text to be italicized</i>. The <head> </head> tags control text that is metadata, and the <body></body> tags surround text that is to be displayed. <a> tags are used for hyperlinks, and have an URL in the following format: <a href=URL>text</a>.

Once your program has read in some HTML, it should simply ignore <html>. It should remove any text from the <head> section so that it doesn't show up when you output it. It should then display all text in the body, modifying it so that any text between a <b> and a </b> will show up
with asterisks (*) around it, any text inside <i> and </i> will show up with underscores (_) around it, and any text with a <a href=linkurl>link text</a> tag shows up as link text (linkurl).