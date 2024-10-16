
#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No commit message provided."
    echo "Usage: ./git_auto_commit.sh \"Your commit message\""
    exit 1
fi
SCENE="$1"
g++ Camera.cpp KeyboardHandler.cpp Scene.cpp Object.cpp EMelements.cpp FpsGun.cpp "$SCENE".cpp -o "$SCENE"  -lGL -lGLU -lglut

./"$SCENE"