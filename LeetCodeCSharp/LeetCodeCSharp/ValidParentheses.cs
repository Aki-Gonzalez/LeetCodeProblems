
namespace LeetCodeCSharp
{

    /*
        Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
        An input string is valid if:

        Open brackets must be closed by the same type of brackets.
        Open brackets must be closed in the correct order.
        Every close bracket has a corresponding open bracket of the same type.

        () valid
        [) invalid
        {()} valid
        [](} invalid

        // Not allowed to use the same solution adapted from C++ => Failed ! Became confusing and a poor solution. Relying on a stack is clearer.

     */
    internal class ValidParentheses
    {
        static public bool IsValid(string s)
        {
            int stringLength = s.Length;
            if (stringLength == 0)
                return false;
            // Uneven string cannot be all matching parentheses.
            if (stringLength % 2 != 0)
                return false;
            
            bool IsClosedParenthesis(char c)
            {
                return c == ')' || c == ']' || c == '}';
            }

            // If first or last char in string is closed respectively open.
            if (IsClosedParenthesis(s[0]) || !IsClosedParenthesis(s[stringLength - 1]))
                return false;

            bool OpenMatchesClosed(char open, char closed)
            {
                if (open == '(')
                    return closed == ')';
                if (open == '[')
                    return closed == ']';
                if (open == '{')
                    return closed == '}';
                return false;
            }

            System.Collections.Generic.Stack<char> openParenthesis = new System.Collections.Generic.Stack<char>();
            openParenthesis.Push(s[0]);
            for(int i = 1; i < stringLength; i++)
            {
                if (IsClosedParenthesis(s[i]))
                {
                    char topOfOpen = '\0';
                    if(openParenthesis.TryPeek(out topOfOpen))
                    {
                        if (OpenMatchesClosed(topOfOpen, s[i]))
                        {
                            openParenthesis.Pop();
                            continue;
                        }      
                    }
                    // There are no open parentheses remaining or there was a mismatch.
                    return false;
                }
                else
                {
                    openParenthesis.Push(s[i]);
                }
            }

            // There should be no openParentheses left.
            return openParenthesis.Count == 0;
        }
    }
}
