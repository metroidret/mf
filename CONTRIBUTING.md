# Important
Anyone wanting to contribute *MUST* read the following and adhere to the steps
outlined, in order to not violate any copyright.

This decompile is a [clean room design](https://en.wikipedia.org/wiki/Clean_room_design).
It *MUST* not incorperate any code owned by Nintendo or other third parties.

In order to achieve this, all code has to be written completely fresh, without
reference to any third party code, no matter if leaked or not.

Derived from this there is the following requirement for contributors:

- Contributors *MUST NOT* study or refer to any code owned by Nintendo or other
  third parties.

# Submitting a Change
1. Clone this repository and follow the setup instructions if you haven't already
2. For any set of changes you want to submit, create a branch off of `main` (make sure you're on the latest commit)
3. When ready to submit your changes, make sure the ROM still compiles (`make`)
4. If the ROM compiles, make sure the ROM still matches the base ROM (`make check`)
- Recommended: run `./check_roms.sh` to build and check ROMs for every supported region (may require `chmod +x check_roms.sh`). You will need a base ROM for each supported region.
5. Open a PR on github, and add a description that summarizes your changes
