echo "Home directory: $HOME"

# Get the operating system type
os_type=$(uname -s)

# Get the operating system version and release number
if [ $os_type = "Linux" ]; then
    os_version=$(grep '^VERSION_ID=' /etc/os-release | cut -d= -f2 | tr -d '"')
    os_release=$(grep '^VERSION=' /etc/os-release | cut -d= -f2 | tr -d '"')
else
    os_version=$(uname -r)
    os_release=$(uname -v)
fi

# Display the operating system information
echo "Operating System: $os_type $os_version $os_release"

# Get the kernel version
kernel_version=$(uname -r)

# Display the kernel version
echo "Kernel Version: $kernel_version"

# Display the current path setting
echo "Current Path Setting: $PATH"