#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/pf/rosWS/src/rqt_common_plugins/rqt_image_view"

# snsure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/pf/rosWS/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/pf/rosWS/install/lib/python2.7/dist-packages:/home/pf/rosWS/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/pf/rosWS/build" \
    "/usr/bin/python" \
    "/home/pf/rosWS/src/rqt_common_plugins/rqt_image_view/setup.py" \
    build --build-base "/home/pf/rosWS/build/rqt_common_plugins/rqt_image_view" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/pf/rosWS/install" --install-scripts="/home/pf/rosWS/install/bin"
