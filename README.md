# Password Generator (Following the iCloud Keychain format)

This program generates passwords following the iCloud Keychain password practises with an entropy of 71 bits ([see Ricky Mondello Password Practies](https://www.youtube.com/watch?v=-0dwX2kf6Oc)):

- 20 characters long
- 3 substrings of 6 letters syllables seperated by a hyphen (-)
- A single digit at either side of the hyphen (-) or at the end of the password
- A single random uppercase letter

[Apple strong password](https://support.apple.com/guide/security/secc84c811c4/web)

The password format is: `cvccvc-cvccvc-cvccvc` where `c` is a consonant and `v` is a vowel.
