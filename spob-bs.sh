#!/bin/bash

set -e

usage() {
    >&2 echo "Usage: $0 <project>"
    exit 1
}

tdir="/var/spob.bs/templates"

pname="$1"
pdir="./${pname}"

[ -z "$pname" ] && usage

if [ ! -d "$tdir" ]; then
    >&2 echo "Unable to find template dir: $tdir"
    >&2 echo "Run init.sh script first"
    exit 2
fi

if [ -e "$pdir" ]; then
    >&2 echo "Project dir already exists: $pdir"
    exit 3
fi

cur="$PWD"
cd "$tdir"

echo "Please select a template:"
select template in *; do
    if [ -n "$template" ]; then
        break
    fi
    echo "Invalid selection."
done

cd "$cur"

cp -R "$tdir/$template" "$pdir"

cd "$pdir"

echo "Customizing project..."

find . -type f -print0 | while IFS= read -r -d '' file; do
    sed -i "s/SPOB/$pname/g" "$file"
done

find . -depth -name "*SPOB*" -print0 | while IFS= read -r -d '' path; do
    new="${path//SPOB/$pname}"
    mv "$path" "$new"
done

echo "Project '$pname' created successfully."

