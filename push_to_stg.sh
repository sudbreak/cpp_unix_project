#!/bin/bash
git checkout stg
git merge dev --no-ff -m "Merge dev into stg"
tag="stg-$(date +%Y%m%d_%H%M%S)"
git tag "$tag"
git push origin stg --tags
git checkout dev
