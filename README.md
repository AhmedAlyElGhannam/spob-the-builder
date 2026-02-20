# spob

> spob can i get a glass of water?

> **angry footsteps climbing stairs**

> NO WAIT NO-

> **gunshot**

<!-- if you are confused and a bit interested, just see this link: https://www.youtube.com/watch?v=u6bSgEp-u3I&pp=ygUfc3BvYiBjYW4gaSBnZXQgYSBnbGFzcyBvZiB3YXRlctIHCQmiCgGHKiGM7w%3D%3D -->


## Introduction
`spob` is a bash-based build system used to generate C/C++/Assembly projects buildable using Make or CMake from a set of templates. This project was inspired by [Dr. Jonas Birch's bash build system]() but I took some liberties and expanded on it. Huge shoutout for the very simple yet very creative idea!

## Installation
* Simply source the `init` script and it does everything for you: installing templates in designated directory, building and installing `spobutils` libraries, and finally creating an alias for `spob-bs` as `spob`.
  ```bash
  ./init.sh
  ```

## Usage
  ```bash
  spob PROJECT_NAME
  # then choose a template to generate it automatically
  ```

