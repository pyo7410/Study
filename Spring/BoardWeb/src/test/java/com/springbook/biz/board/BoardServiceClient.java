package com.springbook.biz.board;

import java.util.List;

import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.GenericXmlApplicationContext;

public class BoardServiceClient {
	
	public static void main(String[] args) {
		// 1. Spring �����̳ʸ� �����Ѵ�.
		AbstractApplicationContext container = new GenericXmlApplicationContext("applicationContext.xml");
		
		// 2. Spring �����̳ʷ� ���� BoardServiceImpl ��ü�� Lookup �Ѵ�.
		BoardService boardService = (BoardService)container.getBean("boardService");
		
		// 3. �� ��� ��� �׽�Ʈ
		BoardVO vo = new BoardVO();
		vo.setTitle("�ӽ� ����");
		vo.setWriter("ȫ�浿");
		vo.setContent("�ӽ� ����..............");
		// Transaction �ǽ�
		//vo.setSeq(100);
		// Transaction �ǽ��� ���� �ּ� ó��
		boardService.insertBoard(vo);
		
		// �� ���� ��� �׽�Ʈ
		/*
		BoardVO vo = new BoardVO();
		vo.setSeq(3);
		boardService.deleteBoard(vo);
		*/
		
		// 4. �� ��� �˻� ��� �׽�Ʈ
		List<BoardVO> boardList = boardService.getBoardList(vo);
		for (BoardVO board : boardList) {
			System.out.println("---> " + board.toString());
		}
		
		// 5. Spring �����̳� ����
		container.close();
	}

}
