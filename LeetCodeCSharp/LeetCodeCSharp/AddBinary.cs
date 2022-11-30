
namespace LeetCodeCSharp
{
    internal class AddBinary
    {
        public static string Solution(string a, string b)
        {
            void AddReversedString(string s, ref List<char> list)
            {
                char[] charArray = s.ToCharArray();
                Array.Reverse(charArray);
                list.AddRange(charArray);
            }

            List<char> sum = new List<char>();
            List<char> shortest = new List<char>();
            if (a.Length > b.Length)
            {
                AddReversedString(a, ref sum);
                AddReversedString(b, ref shortest);
            }
            else
            {
                AddReversedString(b, ref sum);
                AddReversedString(a, ref shortest);
            }

            void AddOne(ref List<char> s, int index)
            {
                if (index >= s.Count)
                    s.Add('0');

                if (s[index] == '0')
                {
                    s[index] = '1';
                    return;
                }

                s[index] = '0';
                AddOne(ref s, index + 1);
            }

            for(int i = 0; i < shortest.Count; i++)
            {
                if (shortest[i] == '1' && sum[i] == '1')
                    AddOne(ref sum, i);
                else if(shortest[i] == '1')
                    sum[i] = '1';
            }

            sum.Reverse();
            return new string(sum.ToArray());
        }
    }
}

/*
 
    Contstraints:
    1 <= a.length, b.length <= 10^4 -> 64bit int should be enough
    a and b consist only of '0' or '1' characters. -> no need to verify parameters validity.
    Each string does not contain leading zeros except for the zero itself.

    Could try converting the string to an int, adding the two ints and then converting back.
    C# has a Convert library.

    sum of ab can be > Int64. Convert.ToString() does not seem to have a 2 bit.

    Possible to parse the string in reverse adding the binary 'by hand'?
    binary is read right to left.
       1010101010
    1010001010101
    

    
    reverse both strings    
    longestLength
    shortestLength
    string sum = longest string 
    
    void AddOne(string, index)
    {
        if index >= string.length
            string.append(0)
        
        if string[index] == 0
            string[index] = 1
            return

        string[index] = 0
        AddOne(string, index + 1)

    }

    for shortestLength
        if shortestString[i] == 1 && sum[i] == 1
            AddOne(string, i)
        else
            sum[i] = 1
        
 */
