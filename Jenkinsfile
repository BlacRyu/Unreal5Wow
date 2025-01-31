/* Requires the Docker Pipeline plugin */
pipeline {
    agent { docker { image 'node:18.16.0-alpine' } }

    options {
        timeout(time: 60, unit: 'MINUTES')
    }
    
    stages {
        stage('helloworld') {
            steps {
                echo 'Hello World!'
            }
        }

        stage('build') {
            steps {
                echo 'Beginning build.'
                bat "BuildProject.bat"
                bat "BuildEditor.bat"
            }

            post {
                success {
                    echo "Build complete."
                }
                failure {
                    echo "Build failed."
                }
            }
        }

        stage('test') {
            steps {
                echo 'Beginning test.'
                bat "RunAllTests.bat"
            }

            post {
                success {
                    echo "All testing completed."
                }
                failure {
                    echo "Testing process failed."
                }
            }
        }
    }
}