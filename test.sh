#!/bin/sh
set -e

make debug

original="$(base64 < Makefile)"
result="$(bin/debug encode Makefile | xargs bin/debug decode | base64)"

if [ "$original" != "$result" ]; then
    echo "Hmm, something went wrong"
    exit 1
fi

echo "All good!"
