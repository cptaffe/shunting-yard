# shunting-yard
An implementation of the shunting-yard algorithm built with gyp.

# Building

If you haven't already, clone chrome's [depot_tools](http://www.chromium.org/developers/how-tos/install-depot-tools) repo and add it to your PATH.

To use `ninja` do

```
export GYP_GENERATORS=ninja
gyp --depth=.
ninja -C out/Default/
```

The binary is now at `out/Default/infix`.
