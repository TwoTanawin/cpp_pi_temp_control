#!/bin/bash

lcov --capture --directory . --output-file coverage/coverage.info
lcov --remove coverage/coverage.info '/usr/*' '*/test/*' --output-file coverage/coverage.info
genhtml coverage/coverage.info --output-directory coverage