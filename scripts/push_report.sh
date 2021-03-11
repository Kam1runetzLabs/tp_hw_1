#!/usr/bin/env bash

git config --global user.email "travis@travis-ci.org"
git config --global user.name "Travis CI" 
git remote add origin-development https://${AUTOBUILD_TOKEN}@github.com/Kam1runetzLabs/technopark_first_hw > /dev/null 2>&1
git add stat-analyze-report-src/ stat-analyze-report-tests/ coverage-report/
git commit --message "Snapshot report N.$TRAVIS_BUILD_NUMBER [ci skip]"
git push origin-development
