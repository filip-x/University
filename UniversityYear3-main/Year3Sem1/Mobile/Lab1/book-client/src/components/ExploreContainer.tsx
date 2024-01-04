import BookList from './BookList/bookList';
import './ExploreContainer.css';

interface ContainerProps { }

const ExploreContainer: React.FC<ContainerProps> = () => {
  return (
    <BookList/>
  );
};

export default ExploreContainer;
