# Remove files you don't want to have git version controled (best before add, commit, and push)
####  find . -type f -name '*.dat' -delete
find . -type f -name '*.o' -delete
find . -type f -name '*.txt' -delete
find . -type f -name '*.ps' -delete
find . -type f -name '*.eps' -delete
# find . -type f -name '*.pdf' -delete
find . -type f -name '*.so' -delete
# find . -type f -name '*.a' -delete
find . -type f -name '*~' -delete
find . -type f -executable -delete
