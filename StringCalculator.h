int isEmptyString (const char* input)
{
  if (str == NULL || str[0] == '\0') {
        return TRUE; // The string is empty
    }
   return FALSE;
}

int add(const char* str)
{
  if(isEmptyString(str) == TRUE)
{
return 0;
}
return -1;
}
