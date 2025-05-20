#!/bin/bash
git checkout prd
git merge stg --no-ff -m "Merge stg into prd"
tag="prd-$(date +%Y%m%d_%H%M%S)"
git tag "$tag"
git push origin prd --tags
git checkout dev
