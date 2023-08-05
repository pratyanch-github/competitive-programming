#include <bits/stdc++.h> 
using namespace std; 

const int base = 256; // number of characters in the input alphabet

void search(const string& pattern, const string& text, int primeNumber) 
{ 
    int patternLength = pattern.length(); 
    int textLength = text.length(); 
    int i, j; 
    int patternHash = 0; // hash value for the pattern 
    int textHash = 0; // hash value for the current window in the text 

    // Calculate the value of base^(patternLength-1) % primeNumber
    int power = 1;
    for (i = 0; i < patternLength - 1; i++) 
        power = (power * base) % primeNumber;

    // Calculate the hash value of the pattern and the first window of the text 
    for (i = 0; i < patternLength; i++) 
    { 
        patternHash = (base * patternHash + pattern[i]) % primeNumber; 
        textHash = (base * textHash + text[i]) % primeNumber; 
    } 

    // Slide the pattern over the text one by one 
    for (i = 0; i <= textLength - patternLength; i++) 
    { 
        // Check the hash values of the current window of text and pattern. 
        // If the hash values match, then only check for characters one by one 
        if (patternHash == textHash) 
        { 
            /* Check for characters one by one */
            for (j = 0; j < patternLength; j++) 
            { 
                if (text[i + j] != pattern[j]) 
                    break; 
            } 

            // If pattern matches with the window in the text 
            if (j == patternLength) 
                cout << "Pattern found at index " << i << endl; 
        } 

        // Calculate the hash value for the next window of text: Remove the leading digit, add the trailing digit 
        if (i < textLength - patternLength) 
        { 
            textHash = (base * (textHash - text[i] * power) + text[i + patternLength]) % primeNumber; 

            // We might get a negative value of textHash, converting it to a positive value 
            if (textHash < 0) 
                textHash = (textHash + primeNumber); 
        } 
    } 
} 

/* Driver code */
int main() 
{ 
    string text = "GEEKS FOR GEEKS"; 
    string pattern = "GEEK"; 
    int primeNumber = 101; // A prime number 
    search(pattern, text, primeNumber); 
    return 0; 
}
