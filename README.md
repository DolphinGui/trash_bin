# Trash Bin

This is trash bin, a header-only library for delayed destruction in c++.

## Why?

Originally this was going to be an attempt at delayed
destruction in c++. This is useless, because it requires
allocating more space whenever you want to delay destruction.

## How?

I guess if you really want to use it, install it using the conanfile. Move stuff into the trash bin using toss(), then
clean it out by using empty().