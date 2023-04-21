# VPPIProject
Short Manual

UI: simple terminal is provided to get actions done.

Basic commands (actions):
# <?>     - "print help", no params
# <close> - "close current document", no params
  --- !!!cannot be executed unless a document is opened!!!
# <new>   - "create new document", 1 param: <math_text/plain_text>
  --- <math_text> is a type of a document for inserting formulas.
  --- a formula is a sequence of numbers separated by +|-|*|/ operations.
  --- nothing else is allowed.
  --- basic example: "1+2-3*123+4/2*3" is a formula whereas "1=2" is not/
  ***
  --- <plain_text> is a type of a document for inserting lines of text.
  --- basic example: "I love C++!" is text.
# <open>  - "open existing document", 1 param : <document_file_name> (just the name of file to open)
# <save>  - "save current document", 1 param : <document_file_name> (just the name of file to save curr document in)
  --- files are by default saved inside "files/" directory
  --- !!!cannot be executed unless a document is opened!!!
# <show>  - "show current document", 0 params
  --- !!!cannot be executed unless a document is opened!!!

When document is open, some additional (header-) commands are suggested:
    # <clear>           - "make document blank", 0 param
DEPENDENT ON DOCUMENT TYPE:
  math_text:
    # <insert_formula>  - "insert a formula and get to the next line", 1 param: <formula> - defined before
    --- !!!cannot be executed unless a formula is input!!!
  plain_text:
    # <insert_text>     - "insert a line of arbitrary text", 1 param: <text> (any input text)

When the document is closed (<close>-command), the attached to it commands (described
before) are removed from the list.

Brief example of usage:

###############################################
Welcome to our Document Editor
What you can do [<command>]:
# <?>
# <close>
# <new>
# <open>
# <save>
# <show>
Awaiting your command...
> new math_text
/---------------------------------------------\
        Math Document Editor:
# <?>
# <clear>
# <close>
# <insert_formula>
# <new>
# <open>
# <save>
# <show>
|---------------------------------------------|

\---------------------------------------------/

> insert_formula 1+2-3*123+4/2*3
> insert_formula 1+2-3
> show
/---------------------------------------------\
        Math Document Editor:
# <?>
# <clear>
# <close>
# <insert_formula>
# <new>
# <open>
# <save>
# <show>
|---------------------------------------------|
1+2-3*123+4/2*3;
1+2-3;

\---------------------------------------------/

> save math1
> close
> new plain_text
/---------------------------------------------\
        Text Document Editor:
# <?>
# <clear>
# <close>
# <insert_text>
# <new>
# <open>
# <save>
# <show>
|---------------------------------------------|

\---------------------------------------------/

> insert_text I love C++! (it seems to be a capybara)
> show
/---------------------------------------------\
        Text Document Editor:
# <?>
# <clear>
# <close>
# <insert_text>
# <new>
# <open>
# <save>
# <show>
|---------------------------------------------|
I love C++! (it seems to be a capybara)

\---------------------------------------------/

> save text1
> close
> ?
# <?>
# <close>
# <new>
# <open>
# <save>
# <show>
> open text1
/---------------------------------------------\
        Text Document Editor:
# <?>
# <clear>
# <close>
# <insert_text>
# <new>
# <open>
# <save>
# <show>
|---------------------------------------------|

I love C++! (it seems to be a capybara)


\---------------------------------------------/

> open math1
***First close the open one.
> close
> open math1
/---------------------------------------------\
        Math Document Editor:
# <?>
# <clear>
# <close>
# <insert_formula>
# <new>
# <open>
# <save>
# <show>
|---------------------------------------------|

1+2-3*123+4/2*3;
1+2-3;


\---------------------------------------------/