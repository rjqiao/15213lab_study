# docker image build -t cmu15213 .

SOURCE_PATH=`pwd`

docker run -v ${SOURCE_PATH}:/app --rm -it cmu15213 /bin/zsh