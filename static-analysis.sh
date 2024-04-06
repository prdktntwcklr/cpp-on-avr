#!/usr/bin/env bash

./build.sh
CodeChecker analyze Build/Avr/compile_commands.json --ignore skip.list --enable sensitive --output Build/Avr/reports
CodeChecker parse Build/Avr/reports/ --export html --output Build/Avr/reports_html
