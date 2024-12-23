# Server/Client Program in C

<h3>Project Overview</h3>
<p>This project involves developing a client-server application using the C programming language under the Linux operating system. The program will implement the following functionalities:</p>

<h3>Functionalities</h3>
<ol>
    <li>
        <b>IPv4 Socket Communication:</b>
        <ul>
            <li>The server program will use stream sockets to communicate with the <code>ClientIPv4_win_2024.exe</code> program.</li>
            <li>The server will listen for client requests on port <b>22228</b>.</li>
            <li>The IPv4 client will be able to connect to all IPv4 addresses assigned to the server.</li>
        </ul>
    </li>
    <li>
        <b>Command Handling:</b>
        <ul>
            <li>The server will process the "08#" command received from <code>ClientIPv4_win_2024.exe</code>.</li>
            <li>An IPv6 client will connect to the HTTP server's URL as specified by the project instructor.</li>
        </ul>
    </li>
    <li>
        <b>Error Handling:</b>
        <ul>
            <li>If the received command does not meet project requirements, the Linux server will return the message <i>"Command not implemented"</i> to the Windows IPv4 client.</li>
        </ul>
    </li>
    <li>
        <b>IPv6 HTTP Communication:</b>
        <ul>
            <li>After establishing IPv6 socket stream communication, the IPv6 client will send the following request to the HTTP server:
                <pre><code>GET / HTTP/1.0\r\n\r\n</code></pre>
            </li>
            <li>The server will:
                <ul>
                    <li>Retrieve the response from the HTTP server.</li>
                    <li>Send the response back to <code>ClientIPv4_win_2024.exe</code>.</li>
                    <li>Save the response locally as a file with the <code>.html</code> extension.</li>
                </ul>
            </li>
        </ul>
    </li>
</ol>

<h3>Project Requirements</h3>
<ul>
    <li><b>Language:</b> C</li>
    <li><b>Operating System:</b> Linux</li>
    <li><b>Client Programs:</b>
        <ul>
            <li><code>ClientIPv4_win_2024.exe</code>: Communicates with the server over IPv4.</li>
            <li>Linux-based IPv6 client: Communicates with the HTTP server over IPv6.</li>
        </ul>
    </li>
</ul>

<h3>Usage</h3>
<ol>
    <li>Compile the server and client programs using GCC or another C compiler on Linux.</li>
    <li>Run the server program and ensure it is listening on port <b>22228</b>.</li>
    <li>Start the client programs and connect to the server as per the specified protocols (IPv4 or IPv6).</li>
</ol>

<h3>Notes</h3>
<ul>
    <li>Ensure the IPv4 client is correctly configured to send the "08#" command to the server.</li>
    <li>Verify that the HTTP server's URL for IPv6 communication matches the project requirements.</li>
    <li>Check that the server correctly saves HTTP responses as <code>.html</code> files in its working directory.</li>
</ul>
