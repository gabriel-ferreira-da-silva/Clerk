
#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No commit message provided."
    echo "Usage: ./git_auto_commit.sh \"Your commit message\""
    exit 1
fi
SCENE="$1"

g++ -Iutils -Iobject -Iscenes utils/Camera.cpp utils/KeyboardHandler.cpp utils/Scene.cpp object/Object.cpp object/EMelements.cpp object/Bullet.cpp object/FpsGun.cpp scenes/"$SCENE".cpp -o scenes/"$SCENE" -lGL -lGLU -lglut

./scenes/"$SCENE"