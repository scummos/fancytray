#!/bin/bash

# launch whatever application you want
kate &

# now create a tray icon; $! is the pid of the launched process
# retry until the application has created a window
app=$!
while [ -e /proc/$app ]; do
  echo "attaching to application" $app
  fancytray $app /usr/share/icons/hicolor/22x22/apps/kate.png
  sleep 1s
done
